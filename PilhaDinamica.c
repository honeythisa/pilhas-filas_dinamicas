//Pilha Din�mica Encadeada
//Implementa��o baseada em Lista Simplesmente Ligada

#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura de um n�
typedef struct Node {
    int data;            // Dado
    struct Node* next;   // Ponteiro para o pr�ximo n�
} Node;

// Fun��o para inicializar a pilha (ponteiro para o topo da pilha)
void initializeStack(Node** top) {
    *top = NULL;
}

// Fun��o para verificar se a pilha est� vazia
int isEmpty(Node* top) {
    return (top == NULL);
}

// Fun��o para criar um novo n�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fun��o para inserir um n� no topo da pilha (push)
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;  // O novo n� aponta para o antigo topo
    *top = newNode;        // O novo topo � o novo n�
}

// Fun��o para remover um n� do topo da pilha (pop)
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Error: Stack is empty!\n");
        return -1;  // Retorno de erro
    }

    Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;  // Atualiza o topo para o pr�ximo n�
    free(temp);
    return poppedValue;
}

// Fun��o para retornar o valor do topo da pilha sem remov�-lo
int topValue(Node* top) {
    if (isEmpty(top)) {
        printf("Error: Stack is empty!\n");
        return -1;  // Retorno de erro
    }
    return top->data;
}

// Fun��o para exibir os elementos da pilha
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

//fun��o para contagem de elementos na pilha sem remov�-los.

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

// Fun��o principal para testar as opera��es da pilha
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

    // Verificando o topo ap�s pop
    printf("Top of stack after pop: %d\n", topValue(stack));
    
    //contagem
    printf("N�mero de elementos na pilha: %d\n", nelements(stack));

    // Verificando se a pilha est� vazia
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    return 0;
}

