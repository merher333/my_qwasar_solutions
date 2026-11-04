int is_anagram(char* a, char* b)
{
    int count[128] = {0};  // ASCII range 32–126 fits in 0–127

    int i = 0;
    while (a[i]) {
        count[(unsigned char)a[i]]++;
        i++;
    }

    i = 0;
    while (b[i]) {
        count[(unsigned char)b[i]]--;
        i++;
    }

    for (i = 32; i <= 126; i++) {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}
