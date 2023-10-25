from Quadratic import Quadratic
import numpy as np


def test_Quadratic():

    f = Quadratic(1, 2, 3)

    tol = 0.0005
    assert abs(f(3) - 18) < tol
    assert abs(f(-1) - 2) < tol


def test_Quadratic_add():

    f = Quadratic(1, 2, 3)
    g = Quadratic(3, 2, 1)
    h = f + g

    f + 3

    assert h.a2 == 4
    assert h.a1 == 4
    assert h.a0 == 4

    assert f.a2 == 4
    assert f.a1 == 5
    assert f.a0 == 6


def test_Quadratic_roots():

    f = Quadratic(1, 2, 3)
    g = Quadratic(1, 2, -2)
    h = Quadratic(1, 2, 1)

    tol = 1e-8
    expected1 = [-1 + np.sqrt(2)*1j, -1 - np.sqrt(2)*1j]
    expected2 = [-1 + np.sqrt(3), -1 - np.sqrt(3)]
    expected3 = -1

    f_result = f.roots()
    g_result = g.roots()
    assert abs(f_result[0] - expected1[0]) < tol
    assert abs(f_result[1] - expected1[1]) < tol
    assert abs(g_result[0] - expected2[0]) < tol
    assert abs(g_result[1] - expected2[1]) < tol
    assert abs(h.roots() - expected3) < tol
