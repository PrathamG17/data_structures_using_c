int IsEmpty()
{
	if(-1==iTop)
		return 1;
	else
		return 0;
}
int IsFull()
{
	if(iTop==20)
		return 1;
	else
		return 0;
}
void Push(int iData)
{
		iTop++;
		iStack[iTop]=iData;
}
int Pop()
{
	int iData;
	iData=iStack[iTop];
	iTop--;
	return iData;
}
int Peek()
{
	int iData;
	iData=iStack[iTop];
	return iData;
}