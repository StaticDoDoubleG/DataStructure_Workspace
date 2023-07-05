//��ǻ�Ͱ��к� 202211390 ���ؿ�
//����ȯ��: Windows 11 64bit

#include "functions.h"
#define current_size 100000

struct ListNode {
	int data;
	struct ListNode* next;
};

//head = NULL;
int array[current_size];

clock_t start;
clock_t end;
unsigned long long count;
int arr_elements = 0;

int main(void) {

	struct ListNode* h = NULL;

	//�л� ����
	printf("��ǻ�Ͱ��к� 202211390 ���ؿ�\n");
	printf("����ȯ��: Windows 11 64bit\n");
	
	while (1) {
		int num;
		printf("\n����� �����ϼ���.\n1/ Insert\n2/ Random Access for Read\n3/ Random Access for Delete\n4/ ����\n\n���� ��ȣ: ");
		if (scanf_s("%d", &num) != 1) {
			printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
			while (getchar() != '\n');
			continue;
		}
		else {
			switch (num) {
			case 1:
				printf("\nInsert ����\n");
				Insert(&h);
				break;
			case 2:
				printf("\nRandom Access for Read ����\n");
				Read(h);
				break;
			case 3:
				printf("\nRandom Access for Delete ����\n");
				Delete(&h);
				break;
			case 4:
				return 0;
			default:
				printf("\n�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ּ���.\n");
				break;
			}
		}
	}
}

//Main Function Declaration
void Insert(struct ListNode** h) {
	//Array Insert
	start = clock();
	for (int i = 0; i < current_size;i++) {
		array_insertion(i, i);
	}
	end = clock();
	printf("Array Insert �ɸ� �ð�: %d ms\n", end - start);

	//LinkedList Insert
	//ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	start = clock();
	for (int i = 0; i < current_size;i++) {
		LinkedList_insertion(&*h, i, 0);
	}
	end = clock();
	printf("LinkedList Insert �ɸ� �ð�: %d ms\n", end - start);
	//info(*h);
}

void Read(struct ListNode* h) {
	unsigned long long add = 0;
	//Array Read
	start = clock();
	int index;
	for (int i = 0; i < current_size;i++) {
		index = (rand() *10) % current_size;
		add += array[index];
	}
	
	printf("\nArray���� ���� ������ ��: %llu", add);
	end = clock();
	printf("\nArray Random Access for Read �ɸ� �ð�: %d ms\n", end - start);
	add = 0;
	//LinkedList Read
	start = clock();
	for (int i = 0; i < current_size;i++) {
		index = (rand() * 10) % current_size;
		//printf("\n%d\n", index);
		//printf("\n%d\n", h);
		add += LinkedList_traverse(h, index);
		//printf("\n%llu\n", add);
		//printf("\n%d\n", LinkedList_traverse(h, index));
	}
	//int index = index = rand() * 10 % current_size;
	
	printf("\nLinkedList���� ���� ������ ��: %llu", add);
	end = clock();
	printf("\nLinkedList Random Access for Read �ɸ� �ð�: %d ms\n", end - start);
}

void Delete(struct ListNode** h) {
	int t = 0;
	int index;
	//Array Delete
	start = clock();
	for (int i = 0; i < current_size;i++) {
		index = (rand() * 10) % (current_size - t);
		for (int j = index;j < current_size - t;j++) {
			array[j] = 0;
			array[j] = array[j + 1];
		}
		array[current_size - t] = 0;
		t++;
	}
	end = clock();
	printf("Array Random Access for Delete �ɸ� �ð�: %d ms\n", end - start);
	t = 0;
	//LinkedList Delete
	start = clock();
	for (int i = 0; i < current_size;i++) {
		index = (rand() * 10) % (current_size - t);
		LinkedList_Deletion(&*h, index);
		t++;
	}
	end = clock();
	printf("LinkedList Random Access for Delete �ɸ� �ð�: %d ms\n", end - start);
}

//Array Function
void array_insertion(int i, int data) {
	if (array[i] == 0) {
		array[i] = data;
	}
	else {
		array[i] = data; //�ϴ� �ִ� �ڸ��� �ִ� �� �������� ����������
	}
}

//LinkedList Function
void LinkedList_insertion(struct ListNode** h, int data, int position) {
	int k = 0;
	struct ListNode* q, * p;
	q = NULL;
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (!newNode) {
		printf("Memory Error\n");
		return;
	}
	newNode->data = data;
	p = *h;
	if (position == 0 || p == NULL) {
		newNode->next = *h;
		//printf("\n%d\n", *h);
		*h = newNode;
		//printf("\n%d\n", newNode->data);
		//printf("\n%d\n", newNode->next);
		//printf("\n%d\n", newNode);
	}
	else {
		while (p != NULL && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		newNode->next = q->next;
		q->next = newNode;
	}
}

int LinkedList_traverse(struct ListNode* h, int position) {
	struct ListNode* current;
	current = h;
	int count = 0;
	//printf("\n���� ��ġ: %d\n", current);

	while (current != NULL && count < current_size) {
		//count++;
		if (position == count) {
			//printf("\ncount: %d\n", count);
			int val = current->data;
			return val;
		}
		//printf("%d\n", val);
		current = current->next;
		count++;
	}
	return 0;
}

void LinkedList_Deletion(struct ListNode** h, int position) {
	int k = 0;
	struct ListNode* p, * q;
	if (*h == NULL) {
		printf("List Empty");
		return;
	}
	p = *h;
	if (position == 0) {  // ����Ʈ ���� �տ��� ����
		*h = p->next;
		free(p);
		return;
	}
	else {   //������ ��ġ���� ����Ʈ Ž���ϱ�
		while ((p != NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (p == NULL)   // ����Ʈ�� ���� �׸��� �����ϴ� ���
			printf("Position does not exist.");
		else {   //����Ʈ �߰� �Ǵ� �ǳ��� �����ϴ� ���
			q->next = p->next;
			free(p);
		}
	}
}

void info(struct ListNode* h) {
	struct ListNode* p;
	p = h;
	int count = 0;
	//printf("\n�̰� ������ p %d\n", p);
	while (p != NULL && count < current_size) {
		printf("\n%d\n", count);
		int val = p->data;
		printf("%d\n", val);
		p = p->next;
		count++;
	}
}
