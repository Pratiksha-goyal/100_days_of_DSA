char* clearDigits(char* s) {
    int n = strlen(s);
    int top = -1;
    char* stack = malloc((n + 1) * sizeof(char));

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            if (top > -1) {
                top--;
            }
        } else {
            stack[++top] = s[i];
        }
    }
    stack[top + 1] = '\0';
    return stack;
}
