int my_islower(char param_1) {
    // Check if the character is between 'a' and 'z'
    if (param_1 >= 'a' && param_1 <= 'z') {
        return 1; // Return 1 for lowercase letters
    }
    return 0; // Return 0 otherwise
}
