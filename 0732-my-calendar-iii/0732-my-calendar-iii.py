class MyCalendarThree(object):
    def __init__(self):
        self.max = collections.defaultdict(int)
        self.lazy = collections.defaultdict(int)

    def update(self, l, r, left=0, right=int(1e9), id=1):
        if right <= l or r <= left: return
        if l <= left and right <= r:
            self.max[id] += 1
            self.lazy[id] += 1
        else:
            md = (left + right) >> 1
            lc, rc = id*2, id*2+1
            self.update(l, r, left, md, lc)
            self.update(l, r, md, right, rc)
            self.max[id] = self.lazy[id] + max(self.max[lc], self.max[rc])

    def book(self, start, end):
        self.update(start, end)
        return self.max[1]