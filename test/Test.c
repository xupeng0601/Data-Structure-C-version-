/*
 * @Author: Dennis Chow
 * @Date: 2020-07-16 16:11:22
 * @Last Modified time: 2020-07-16 16:37:08
 */
#include <stdio.h>
#include <stdlib.h>

#define uint unsigned int

//�ڵ�ṹ��
typedef struct NODE
{
    int data;           // ����
    struct NODE *next;  // �ڵ�ָ��
} Node;

Node *headNode = NULL;  // ͷ�ڵ�
Node *endNode = NULL;   // β�ڵ�

Node* CreateNode(int data);             // �����ڵ�
void AddNode(int data);                 // ���ӽڵ�
uint GetListSize(void);                 // ��ȡ��С
Node* FindNode(uint index);             // ���ҽڵ�
void ReadNode(uint index);              // ��ȡ�ڵ�
void ReadList(void);                    // ��ȡ����
void SetNode(uint index, int data);     // ���ýڵ�
void DeleteList(void);                  // ɾ������
void DeleteNode(uint index);            // ɾ���ڵ�
void InsertNode(uint index, int data);  // ����ڵ�

int main()
{
    // ���ӽڵ�
    AddNode(11);
    AddNode(22);
    AddNode(33);
    AddNode(44);
    AddNode(55);
    AddNode(66);

    // ���ýڵ�
    SetNode(3, 99);

    // ��ȡ��С
    printf("Linked list size: %d\n\n", GetListSize());

    // ��ȡ����
    ReadList();

   /* // ��ȡ�ڵ�
    ReadNode(2);

    // ɾ���ڵ�
    DeleteNode(0);  // ͷ�ڵ�
    DeleteNode(2);  // �м�ڵ�
    DeleteNode(GetListSize() - 1);  // β�ڵ�

    // ��ȡ��С
    printf("Linked list Size: %d\n\n", GetListSize());

    // ����ڵ�
    InsertNode(0, 7);    // ͷ�ڵ�����
    InsertNode(2, 8);    // �м�ڵ�����
    InsertNode(GetListSize() - 1, 9);    // β�ڵ�����

    // ��ȡ����
    ReadList();

    // ɾ������
    DeleteList();
*/
    return 0;
}

Node* CreateNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}
void AddNode(int data)
{
    Node *node = CreateNode(data);

    if (headNode == NULL)   //����Ϊ��
    {
        headNode = node;
    }
    else  //�����Ѵ��ڽڵ�
    {
        endNode->next = node;
    }

    endNode = node;
}

uint GetListSize(void)
{
    Node *node = headNode;
    uint size = 0;

    while (node != NULL)
    {
        node = node->next;
        size++;
    }

    return size;
}

Node* FindNode(uint index)
{
    Node *node = headNode;
    uint currentIndex = 0;

    if (node == NULL)
    {
        printf("����Ϊ�գ�\n");
        return NULL;
    }

    while (node != NULL)
    {
        if (index == currentIndex)
        {
            return node;
        }

        node = node->next;
        currentIndex++;
    }

    return NULL;
}

void ReadNode(uint index)
{
    Node *node = FindNode(index);   // ���ҽڵ�

    if (node == NULL)
    {
        printf("�޴˽ڵ㣡\n");
    }
    else
    {
        printf("%s: Node%d's data = %d\n\n", __FUNCTION__, index, node->data);
    }
}

void ReadList(void)
{
    Node *node = headNode;
    if (node == NULL)
    {
        printf("����Ϊ�գ�\n");
    }
    else
    {
        for (int index = 0; index < GetListSize(); index++)
        {
            printf("%s: Node%d's data = %d\n", __FUNCTION__, index, node->data);
            node = node->next;
        }
        printf("\n");
    }
}

void SetNode(uint index, int data)
{
    Node *node = FindNode(index);   // ���ҽڵ�

    if (node == NULL)
    {
        printf("�޴˽ڵ㣡\n");
        return;
    }

    node->data = data;
}

void DeleteList(void)
{
    Node *node = headNode;

    if (node == NULL)
    {
        printf("����Ϊ�գ�\n");
        return;
    }

    while (node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }

    headNode = NULL;
    endNode = NULL;

    printf("%s: The LINKED LIST has cleaned.\n", __FUNCTION__);
}

void DeleteNode(uint index)
{
    Node *foundNode = FindNode(index);   // ���ҽڵ�

    if (foundNode == NULL)  // �޴˽ڵ�
    {
        return;
    }
    else
    {
        Node *node = headNode;

        if (headNode == endNode)    // ֻ��һ���ڵ�
        {
            free(headNode);
            headNode = NULL;
            endNode = NULL;
        }
        else    // ����һ���ڵ�
        {

            if (foundNode == headNode) // ɾ��ͷ�ڵ�
            {
                Node *oldHeadNode = headNode;   // �ݴ�ɽڵ�
                headNode = headNode->next;      // ���ڶ����ڵ�����Ϊ��ͷ�ڵ�
                free(oldHeadNode);              // �ͷ�ͷ�ɽڵ���ڴ�
            }
            else if (foundNode == endNode)   // ɾ��β�ڵ�
            {
                while (node->next != foundNode) // �ҵ�Ҫɾ���Ľڵ�
                {
                    node = node->next;
                }

                // �������ڶ����ڵ��next��ΪNULL����൱������Ϊβ�ڵ�
                node->next = NULL;
                free(foundNode);    //�ͷű�ɾ�ڵ���ڴ�
            }
            else    // ɾ���м��ĳ�ڵ�
            {
                while (node->next != foundNode) // �ҵ�Ҫɾ���Ľڵ�
                {
                    node = node->next;
                }

                // �� ��ɾ�ڵ� �� ��һ���ڵ��next ����Ϊ ��ɾ�ڵ� �� ��һ���ڵ�
                node->next = foundNode->next;
                free(foundNode);    //�ͷű�ɾ�ڵ���ڴ�
            }
        }
    }

    printf("Node%d has deleted!\n\n", index);
}

void InsertNode(uint index, int data)
{
    Node *newNode = CreateNode(data);
    Node *insertNode = FindNode(index);

    if (headNode == NULL)
    {
        printf("����Ϊ�գ�\n");
        return;
    }
    else if (insertNode == NULL)
    {
        printf("�޴˽ڵ㣡\n");
        return;
    }
    else
    {
        // ���½ڵ��next ����Ϊ ��ǰ����λ�ýڵ� �� ��һ���ڵ�
        newNode->next = insertNode->next;

        // �� ��ǰ����λ�ýڵ��next ����Ϊ newNode
        insertNode->next = newNode;
    }
}
