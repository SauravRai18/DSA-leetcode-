#define SIZE 10007

typedef struct Node {

    int value;
    struct Node *next;

} Node;

int hash(int num) {

    if(num < 0) {
        num = -num;
    }

    return num % SIZE;
}

bool containsDuplicate(int *nums, int numsSize) {

    Node *table[SIZE] = {NULL};

    for(int i = 0; i < numsSize; i++) {

        int index = hash(nums[i]);

        Node *temp = table[index];

        while(temp != NULL) {

            if(temp->value == nums[i]) {
                return true;
            }

            temp = temp->next;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));

        newNode->value = nums[i];

        newNode->next = table[index];

        table[index] = newNode;
    }

    return false;
}