//Ħ��ͶƱ��
int majorityElement(int* nums, int numsSize)
{
    int count=0;//��¼���� 
    int number=nums[0];//��¼��ֵ 
    for(int i=0; i<numsSize; i++)
    {
        if(count==0) //�������˸����������ͶƱ 
        {
            number=nums[i];
            count=1;
        }
        else if(number!=nums[i]) //��ͬ���һ��������� 
            count--;
        else
            count++;
    }
    return number;
}
