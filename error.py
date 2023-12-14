
def calculate_relative_error(data1, data2):
    """
    Calculate the relative error between two datasets. Relative error is 
    calculated for each data point as the absolute error divided by 
    the absolute value of the reference data point. 

    Note: If a reference data point is zero, the relative error for that point is set 
    to None to avoid division by zero.

    :param data1: List or array of reference data points (e.g., data the standard system).
    :param data2: List or array of comparison data points (e.g., data from the new system).
    :return: A list of relative errors for each data point.
    """
    if len(data1) != len(data2):
        raise ValueError("The two datasets must have the same number of elements")

    relative_errors = []
    for x, y in zip(data1, data2):
        if x == 0:
            relative_errors.append(None)  # Append None if the reference value is zero
        else:
            relative_errors.append(abs(x - y) / abs(x))

    return relative_errors


def calculate_rmse(data1, data2):
    """
    Calculate the Root Mean Square Error (RMSE) between two datasets.

    :param data1: List or array of data points from the first dataset.
    :param data2: List or array of data points from the second dataset.
    :return: The RMSE value as a float.
    """
    if len(data1) != len(data2):
        raise ValueError("The two datasets must have the same number of elements")

    squared_errors = [(x - y) ** 2 for x, y in zip(data1, data2)]
    mse = sum(squared_errors) / len(data1)
    rmse = mse ** 0.5
    return rmse


def calculate_mae(data1, data2):
    """
    Calculate the Mean Absolute Error (MAE) between two datasets.

    :param data1: List or array of data points from the first dataset.
    :param data2: List or array of data points from the second dataset.
    :return: The MAE value as a float.
    """
    if len(data1) != len(data2):
        raise ValueError("The two datasets must have the same number of elements")

    absolute_errors = [abs(x - y) for x, y in zip(data1, data2)]
    mae = sum(absolute_errors) / len(data1)
    return mae


