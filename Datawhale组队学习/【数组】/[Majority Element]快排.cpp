int majorityElement(int* nums, int numsSize)
{
    //ʹ������ķ�ʽ�������е���������������������������м䣨n/2���������Ǿ�������
	void quickSort(int* nums,int first,int end);
	quickSort(nums,0,numsSize-1); //����
    return nums[numsSize/2];
}

void quickSort(int* nums,int first,int end)
{  
    int temp,l,r;  
    if(first>=end)
		return;  
    temp=nums[first];  
    l=first;r=end;  
    while(l<r)
	{  
        while(l<r && nums[r]>=temp)
			r--;  
        if(l<r)
			nums[l]=nums[r];  
        while(l<r && nums[l]<=temp)
			l++;  
        if(l<r)
			nums[r]=nums[l];  
    }  
    nums[l]=temp;  
    quickSort(nums,first,l-1);  
    quickSort(nums,l+1,end);  
} //����

