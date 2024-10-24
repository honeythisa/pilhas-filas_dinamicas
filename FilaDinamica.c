//Fila Dinâmica Encadeada
//Implementação baseada em Lista Simplesmente Ligada

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó
typedef struct Node {
    int data;            // Dado
    struct Node* next;   // Ponteiro para o próximo nó
} Node;

// Estrutura para a fila
typedef struct Queue {
    Node* front;         // Ponteiro para o primeiro nó (início da fila)
    Node* rear;          // Ponteiro para o último nó (fim da fila)
} Queue;

// Função para inicializar a fila
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para enfileirar (inserir no final da fila)
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    
    if (queue->rear == NULL) {
        // Se a fila estiver vazia, o novo nó é tanto o front quanto o rear
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Inserir o novo nó no final da fila
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar (remover do início da fila)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty!\n");
        return -1;  // Retorno de erro
    }

    Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;  // Atualiza o front para o próximo nó

    if (queue->front == NULL) {
        // Se a fila ficar vazia, rear também deve ser NULL
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Função para retornar o valor do início da fila sem removê-lo
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty!\n");
        return -1;  // Retorno de erro
    }
    return queue->front->data;
}

// Função para exibir os elementos da fila
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

// Função principal para testar as operações da fila
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

    // Verificando o valor do início da fila
    printf("Front of queue: %d\n", front(&queue));

    // Removendo elementos (dequeue)
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Queue after dequeue: ");
    displayQueue(&queue);

    // Verificando o valor do início após dequeue
    printf("Front of queue after dequeue: %d\n", front(&queue));
    
    printf("Soma dos elementos na fila: %d\n", sum(&queue));

    // Verificando se a fila está vazia
    if (isEmpty(&queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}

