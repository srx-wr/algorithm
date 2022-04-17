#include"Queue.h"

void testQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q); 
	//QueuePop(&q);
	//QueuePop(&q);
	printf("%d ", QueueFront(&q)); // 2
	printf("%d ", QueueBack(&q));

	printf("%d ", QueueSize(&q));
	QueueDestroy(&q);

}

int main()
{
	testQueue();
	return 0;
}