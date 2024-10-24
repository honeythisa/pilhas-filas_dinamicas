//Fila Din�mica Encadeada
//Implementa��o baseada em Lista Simplesmente Ligada

#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura de um n�
typedef struct Node {
    int data;            // Dado
    struct Node* next;   // Ponteiro para o pr�ximo n�
} Node;

// Estrutura para a fila
typedef struct Queue {
    Node* front;         // Ponteiro para o primeiro n� (in�cio da fila)
    Node* rear;          // Ponteiro para o �ltimo n� (fim da fila)
} Queue;

// Fun��o para inicializar a fila
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Fun��o para verificar se a fila est� vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para enfileirar (inserir no final da fila)
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    
    if (queue->rear == NULL) {
        // Se a fila estiver vazia, o novo n� � tanto o front quanto o rear
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Inserir o novo n� no final da fila
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Fun��o para desenfileirar (remover do in�cio da fila)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty!\n");
        return -1;  // Retorno de erro
    }

    Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;  // Atualiza o front para o pr�ximo n�

    if (queue->front == NULL) {
        // Se a fila ficar vazia, rear tamb�m deve ser NULL
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Fun��o para retornar o valor do in�cio da fila sem remov�-lo
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty!\n");
        return -1;  // Retorno de erro
    }
    return queue->front->data;
}

// Fun��o para exibir os elementos da fila
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// soma
int sum(Queue* queue)
{
	int n = 0;
	Node* temp= queue->front;
	while(temp!=NULL)
	{
		n+=temp->data;
		temp=temp->next;
	}
	return n;
}

// Fun��o principal para testar as opera��es da fila
int main() {
    Queue queue;
    
    // Inicializando a fila
    initializeQueue(&queue);

    // Inserindo elementos (enqueue)
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Queue after enqueues: ");
    displayQueue(&queue);

    // Verificando o valor do in�cio da fila
    printf("Front of queue: %d\n", front(&queue));

    // Removendo elementos (dequeue)
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Queue after dequeue: ");
    displayQueue(&queue);

    // Verificando o valor do in�cio ap�s dequeue
    printf("Front of queue after dequeue: %d\n", front(&queue));
    
    printf("Soma dos elementos na fila: %d\n", sum(&queue));

    // Verificando se a fila est� vazia
    if (isEmpty(&queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}

