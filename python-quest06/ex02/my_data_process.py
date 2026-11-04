def my_data_process(param_1):
    header = param_1[0].split(",")
    columns_to_keep = ["Gender", "Email", "Age", "City", "Device", "Order At"]
    indices_to_keep = [header.index(col) for col in columns_to_keep]
    result = {col: {} for col in columns_to_keep}
    for row in param_1[1:]:
        if not row.strip():
            continue
        values = row.split(",")
        for i, col in zip(indices_to_keep, columns_to_keep):
            value = values[i]
            result[col][value] = result[col].get(value, 0) + 1

    import json
    return json.dumps(result, separators=(",", ":"))

