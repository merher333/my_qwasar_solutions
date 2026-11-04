int my_isalpha(char param_1) {
    // Check if the character is between 'A' and 'Z' or 'a' and 'z'
    if ((param_1 >= 'A' && param_1 <= 'Z') || (param_1 >= 'a' && param_1 <= 'z')) {
        return 1; // Return 1 for alphabetic characters
    }
    return 0; // Return 0 otherwise
}

