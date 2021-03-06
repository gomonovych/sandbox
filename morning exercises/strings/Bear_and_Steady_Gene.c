
int steadyGene(char* gene) {
    
    if (gene == NULL) return 0;
    if (strlen(gene) < 4) return 0;
    
    int fr[4] = {0};
    
    char *s = gene;
    int n = strlen(gene);
    int n4 = n/4;
    
    while (*s != '\0')// A C G T
    {
        switch(*s) {
            case 'A': fr[0]++; break;
            case 'C': fr[1]++; break;
            case 'G': fr[2]++; break;
            case 'T': fr[3]++; break;
        }
        ++s;
    }

    int a, c, g, t;
    int A, C, G, T;
    A = fr[0]-n4;
    C = fr[1]-n4;
    G = fr[2]-n4;
    T = fr[3]-n4;
    A=A<0?0:A; C=C<0?0:C; G=G<0?0:G; T=T<0?0:T; 

    if (A==0 && C==0 && G==0 && T==0) return 0;

    int min = 1000000;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        s = &gene[i];
        a = A; c = C; g = G; t = T;
        while ( *s != '\0' && (a || c || g || t) )
        {
            if (*s=='A' && a>0) a--;
            if (*s=='C' && c>0) c--;
            if (*s=='G' && g>0) g--;
            if (*s=='T' && t>0) t--;
            s++;
        }
        bool dec = true;
        while ( dec )
        {
            dec = false;
            if (gene[i]=='A' && A==0) i++, dec=true;
            else if (gene[i]=='C' && C==0) i++, dec=true;
            else if (gene[i]=='G' && G==0) i++, dec=true;
            else if (gene[i]=='T' && T==0) i++, dec=true;
        }
        if (!a && !c && !g && !t)
        {
            int len = s - &gene[i];
            min = len < min ? len : min;
        }
    }

    return min;
}




int fr[300] = {0};
int steadyGene(char* gene)
{
    int n = strlen(gene);
    int n4 = n/4;
    int left = 0;
    int right = n-1;
    char *s = gene;
    int minlen = n;
    
    while (right >= 0) {
        fr[s[right]]++;
        if (fr[s[right]] == n4)
            break;
        right--;
    }
    while (left < n) {
        fr[s[left]]++;
        while (right < n && fr[s[left]] > n4)
        {
            fr[s[right]]--;
            right++;
        }
        left++;
        minlen = minlen < (right-left) ? minlen : (right-left);
        if (n == right)
            break;
    }
    return minlen;
}
