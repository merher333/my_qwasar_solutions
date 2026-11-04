"""
:type param_1: {String}
:type param_2: {Character}
:rtype: integer
"""
def my_string_index(param_1, param_2):
    for index, char in enumerate(param_1):
        if char == param_2:
            return index
    return -1

