import pandas as pd
from io import StringIO
from sklearn.metrics import mean_absolute_error


def _to_df(data):
    if isinstance(data, str):
        data = StringIO(data)
    return pd.read_csv(data).iloc[:, 1:]


def my_model_evaluation_journey_mean_absolute_error(param_1, param_2):
    df_true = _to_df(param_1)
    df_pred = _to_df(param_2)
    n = min(len(df_true), len(df_pred))
    return mean_absolute_error(df_true.iloc[:n], df_pred.iloc[:n])
