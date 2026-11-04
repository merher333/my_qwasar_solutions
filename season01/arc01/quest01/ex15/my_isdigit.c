int my_isdigit(char param_1) {
    // Check if the character is between '0' and '9'
    if (param_1 >= '0' && param_1 <= '9') {
        return 1; // Return 1 for digits
    }
    return 0; // Return 0 otherwise
}
