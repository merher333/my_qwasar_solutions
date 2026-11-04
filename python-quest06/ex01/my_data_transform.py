def my_data_transform(csv_content):
    rows = csv_content.strip().split("\n")
    header = rows[0]
    data_rows = rows[1:]
    transformed_rows = [header]

    for row in data_rows:
        columns = row.split(",")

        # Processing the email
        columns[4] = columns[4].split("@")[1]

        # Processing the age
        age = int(columns[5])
        if 1 <= age <= 20:
            columns[5] = "1->20"
        elif 21 <= age <= 40:
            columns[5] = "21->40"
        elif 41 <= age <= 65:
            columns[5] = "41->65"
        else:
            columns[5] = "66->99"

        # Processing the order time
        import datetime
        order_time = datetime.datetime.strptime(columns[9], '%Y-%m-%d %H:%M:%S')
        if 6 <= order_time.hour < 12:
            columns[9] = "morning"
        elif 12 <= order_time.hour < 18:
            columns[9] = "afternoon"
        else:
            columns[9] = "evening"

        # Adding the transformed row
        transformed_rows.append(",".join(columns))

    return [row for row in transformed_rows]


# Testing the function
csv_test = (
    "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\n"
    "Male,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\n"
    "Male,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\n"
    "Female,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\n"
    "Female,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\n"
    "Male,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"
)

result = my_data_transform(csv_test)
