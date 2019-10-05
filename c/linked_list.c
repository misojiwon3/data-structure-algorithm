#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int data;
};

void addNode(struct Node *target, int data) { // target 의 뒤에 data를 가진 노드 추가한다
    struct Node *newNode = malloc(sizeof(struct Node));
    
    newNode->next = target->next; // 새 노드의 next에 target의 next 할당
    target->next = newNode; // target의 next에 새로 생성한 노드의 주소 연결
    newNode->data = data; // 새 노드의 data 에 매개변수 data 할당
}

void removeNode(struct Node *target) {
    struct Node *delNode = target->next; // 삭제할 노드 찾은 후
    target->next = delNode->next; // 삭제할 노드가 가리키는 노드를 target이 가리키도록 할당
    
    free(delNode); // 삭제할 노드의 메모리 해제
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    
    struct Node *node1 = malloc(sizeof(struct Node)); // 노드에 메모리 할당
    head->next = node1; // 헤드의 다음 노드는 node1
    node1->data = 10; // node1의 data에 10 할당
    
    struct Node *node2 = malloc(sizeof(struct Node));
    node1->next = node2;
    (*node2).data = 20;
    
    node2->next = NULL;
    
    addNode(head, 5);
    addNode(node1, 15);
    addNode(node2, 25);
    
    // head -> 5 -> node1 -> 15 -> node2 -> 25
    
    // 노드 순회
    struct Node *curr = head->next;
    
    while(curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    
    removeNode(node1);
    removeNode(node2);
    
    // head -> 5 -> 15 -> 25
    
    // 노드 순회
    curr = head->next;
    
    while(curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    
    curr = head->next;
    while(curr != NULL) {
        printf("free %p, %d\n", curr, curr->data);
        struct Node *n = curr->next;
        free(curr);
        curr = n;
    }
    
    free(head);
    
    return 0;
}

