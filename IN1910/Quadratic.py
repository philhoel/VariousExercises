import numpy as np


class Quadratic:

    def __init__(self, a2, a1, a0) -> None:
        self.a0 = a0
        self.a1 = a1
        self.a2 = a2

    def __call__(self, x) -> float:
        return self.a2*x*x + self.a1*x + self.a0

    def __str__(self) -> str:
        return f"{self.a2} * x^2 + {self.a1} * x + {self.a0}"

    def __add__(self, other):
        if type(other) == bool:
            raise TypeError

        if isinstance(other, (int, float)):
            self.a2 += other
            self.a1 += other
            self.a0 += other
        elif isinstance(other, Quadratic):
            return Quadratic(self.a2 + other.a2, self.a1 + other.a1, self.a0 + other.a0)
        else:
            raise TypeError

    def roots(self):

        a = self.a2
        b = self.a1
        c = self.a0

        d = (b**2 - 4 * a * c)
        if d == 0:
            x = -b/(2*a)
        elif d > 0:
            x = [(-b + np.sqrt(d))/(2*a), (-b - np.sqrt(d))/(2*a)]
        else:
            x = [(-b + np.sqrt(-d)*1j)/(2*a), (-b - np.sqrt(-d)*1j)/(2*a)]

        return x

    def intersect(self, other):

        if not isinstance(other, Quadratic):
            raise TypeError


f = Quadratic(1, 2, 2)
print(f)
print(f.roots())
print([-1 + np.sqrt(3), -1 - np.sqrt(3)])
