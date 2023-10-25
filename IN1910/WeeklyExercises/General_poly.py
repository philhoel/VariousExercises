from typing import Any
import numpy as np


class Polynomial:

    def __init__(self, coeffs: dict) -> None:
        self.coeffs = coeffs

    def __call__(self, x: float) -> Any:
        s = 0
        for key in self.coeffs:
            s += self.coeffs[key]*np.power(x, key)

        return s

    def __str__(self) -> str:
        s = ""
        for key in self.coeffs:
            if key == 0:
                s += f"{self.coeffs[key]}"
            else:
                s += f"{self.coeffs[key]} * x^{key}"

            s += " + "

        s = s[:-2]

        return s

    def __add__(self, other):

        if not isinstance(other, Polynomial):
            raise TypeError

        new_coeffs = self.coeffs

        for key in other.coeffs:
            if key not in self.coeffs.keys():
                new_coeffs[key] = other.coeffs[key]
            else:
                new_coeffs[key] += other.coeffs[key]

        new_poly = Polynomial(new_coeffs)
        return new_poly

    def __mul__(self, other):

        if not isinstance(other, Polynomial):
            raise TypeError

        new_coeffs = self.coeffs


f = Polynomial({0: 1, 5: -7, 10: 1})
g = Polynomial({5: 7, 10: 1, 15: -3})
print(f + g)
