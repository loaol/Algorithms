void MergeList_List_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    LinkList pa=La->next,pb=Lb->next,pc;
    Lc=pc=La;      //��La��ͷ�����ΪLc��ͷ���
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;   //����ʣ���
    free(Lb);            //�ͷ�Lb��ͷ���
}
