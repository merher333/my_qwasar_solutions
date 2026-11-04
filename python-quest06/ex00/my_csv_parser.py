def my_csv_parser(param_1, param_2):
    rows = param_1.strip().split("\n")
    result = [row.split(param_2) for row in rows]
    return result

