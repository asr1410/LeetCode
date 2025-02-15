class ProductOfNumbers:

    def __init__(self):
        self.cnt = [(1, 0)]  # (prefix product, zero count)

    def add(self, num: int) -> None:
        if num == 0:
            self.cnt.append((self.cnt[-1][0], self.cnt[-1][1] + 1))  # Keep same product, increment zero count
        else:
            self.cnt.append((self.cnt[-1][0] * num, self.cnt[-1][1]))  # Multiply product, keep zero count same

    def getProduct(self, k: int) -> int:
        if self.cnt[-1][1] - self.cnt[-(k + 1)][1] > 0:  # Check if zero exists in range
            return 0
        return self.cnt[-1][0] // self.cnt[-(k + 1)][0]  # Compute product using division


# Example Usage:
# obj = ProductOfNumbers()
# obj.add(3)
# obj.add(4)
# obj.add(2)
# obj.add(0)
# obj.add(5)
# obj.add(6)
# print(obj.getProduct(3))  # Output: 0
# print(obj.getProduct(2))  # Output: 30
