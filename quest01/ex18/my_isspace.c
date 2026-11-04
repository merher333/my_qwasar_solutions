int my_isspace(char param_1) {
    // Check if the character is a whitespace character
    if (param_1 == ' ' || param_1 == '\t' || param_1 == '\n' ||
        param_1 == '\v' || param_1 == '\f' || param_1 == '\r') {
        return 1; // Return 1 for whitespace characters
    }
    return 0; // Return 0 otherwise
}
