import pandas as pd
from io import StringIO
from sklearn.metrics import r2_score


def _to_df(data):
    if isinstance(data, str):
        data = StringIO(data)
    return pd.read_csv(data).iloc[:, 1:]


def my_model_evaluation_journey_r2_score(param_1, param_2):
    df_true = _to_df(param_1)
    df_pred = _to_df(param_2)
    n = min(len(df_true), len(df_pred))
    return r2_score(df_true.iloc[:n], df_pred.iloc[:n])
