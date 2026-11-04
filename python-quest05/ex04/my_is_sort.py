"""
:type  param_1: {Integer[]}
:rtype: boolean
"""
def my_is_sort(param_1):
    if param_1 == sorted(param_1) or param_1 == sorted(param_1, reverse=True):
        return True
    return False
