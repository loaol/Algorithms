char* reverseWords(char* s) {
    // ��ɾ������ո�
    int count = 0;
    int i = 0;
    while(s[count] == ' ' && ++count); // ������ͷ�Ŀո�
    while(s[count])
        if(s[count] != ' ' || s[count+1] != ' ')
            s[i++] = s[count++];
        else
            s[i] = s[++count];
    s[i] = 0;
    if(s[0] && s[i-1] == ' ') // ĩβ����ʣһ���ո�
        s[i-1] = 0;
    // ������תÿ������
    int l, r;
    i = 0;
    while(s[i]) {
        l = i;
        r = i;
        while(s[r] != ' ' && s[r] != 0 && ++r)
            i = s[r] == ' '? r+1: r;
        while(l < r-1)
        {
            int temp = s[l];
            s[l++] = s[--r];
            s[r] = temp;
        }
    }
    
    // ��ת�����ַ���
    l = 0;
    r = strlen(s) - 1;
    while(l < r)
    {
        int temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
    
    return s; 
}
