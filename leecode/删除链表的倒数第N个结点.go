/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	count, prev := sub_remove(head, n)
	if count == n {
		head = prev
	}
	return head
}

func sub_remove(curr *ListNode, n int) (int, *ListNode) {
	if curr.Next == nil {
		return 1, nil
	}
	count, prev := sub_remove(curr.Next, n)
	if count == n {
		curr.Next = prev
	}
	return count + 1, curr.Next
}
