//Pilha Dinâmica Encadeada
//Implementação baseada em Lista Simplesmente Ligada

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó
typedef struct Node {
    int data;            // Dado
    struct Node* next;   // Ponteiro para o próximo nó
} Node;

// Função para inicializar a pilha (ponteiro para o topo da pilha)
void initializeStack(Node** top) {
    *top = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(Node* top) {
    return (top == NULL);
}

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no topo da pilha (push)
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;  // O novo nó aponta para o antigo topo
    *top = newNode;        // O novo topo é o novo nó
}

// Função para remover um nó do topo da pilha (pop)
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Error: Stack is empty!\n");
        return -1;  // Retorno de erro
    }

    Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;  // Atualiza o topo para o próximo nó
    free(temp);
    return poppedValue;
}

// Função para retornar o valor do topo da pilha sem removê-lo
int topValue(Node* top) {
    if (isEmpty(top)) {
        printf("Error: Stack is empty!\n");
        return -1;  // Retorno de erro
    }
    return top->data;
}

// Função para exibir os elementos da pilha
void displayStack(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }

    Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//função para contagem de elementos na pilha sem removê-los.

int nelements (Node* top){
	int n = 0;
	Node* temp = top;
	while(temp!=NULL)
	{
		temp = temp->next;
		n++;
	}
	return n;
}

// Função principal para testar as operações da pilha
int main() {
    Node* stack;
    
    // Inicializando a pilha
    initializeStack(&stack);

    // Inserindo elementos (push)
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack after pushes: ");
    displayStack(stack);

    // Verificando o topo da pilha
    printf("Top of stack: %d\n", topValue(stack));

    // Removendo elementos (pop)
    printf("Popped: %d\n", pop(&stack));
    printf("Stack after pop: ");
    displayStack(stack);

    // Verificando o topo após pop
    printf("Top of stack after pop: %d\n", topValue(stack));
    
    //contagem
    printf("Número de elementos na pilha: %d\n", nelements(stack));

    // Verificando se a pilha está vazia
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    return 0;
}

