void compete(Hanger *hanger, int *ele, int *temp, int level)
{
    if (!hanger->deck[level].container && level < hanger->stretch)
    {
        hanger->deck[level].container = 1;
        for (int i = 0; i <= level; i++)
        {
            hanger->deck[level].chart[i] = ele[i];
        }
    }
    else
    {
        hanger->deck[level].container = 0;
        for (int i = 0; i <= level; i++)
        {
            printf("%d ", ele[i]);
        }
        printf("X ");
        for (int i = 0; i <= level; i++)
        {
            printf("%d ", hanger->deck[level].chart[i]);
        }
        printf(" = ");
        int i = 0, j = 0, pos = 0;
        while (i <= level && j <= level)
        {
            if (ele[i] > hanger->deck[level].chart[j])
                temp[pos++] = ele[i++];
            else
                temp[pos++] = hanger->deck[level].chart[j++];
        }
        while (i <= level)
            temp[pos++] = ele[i++];
        while (j <= level)
            temp[pos++] = hanger->deck[level].chart[j++];
        for (int i = 0; i < pos; i++)
        {
            hanger->deck[level].chart[i] = temp[i];
        }
        for (int i = 0; i <= level + 1; i++)
        {
            printf("%d ", temp[i]);
        }
        printf("\n");
        compete(hanger, hanger->deck[level].chart, temp, level + 1);
    }
}