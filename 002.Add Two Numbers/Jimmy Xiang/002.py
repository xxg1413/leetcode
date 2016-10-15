class ListNode:
    def __init__(self, v):
        self.val = v
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        head = ListNode(0)
        current, carry = head, 0

        while l1 or l2:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next

            carray,val = val / 10, val % 10
            current.next = ListNode(val)
            current = current.next

            if carray == 1:
                current.next = ListNode(1)

        return head.next

def main():
    a,a.next,a.next.next = ListNode(2),ListNode(4), ListNode(3)
    b, b.next, b.next.next = ListNode(5), ListNode(6), ListNode(4)
    result = Solution().addTwoNumbers(a, b)
    print "{0} -> {1} -> {2}".format(result.val, result.next.val, result.next.next.val)


if __name__ == "__main__":
    main()
