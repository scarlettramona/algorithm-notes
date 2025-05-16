bool is_cycle(ListNode *head)
{
    if(!head || !head->next)
        return false;

    ListNode* hare = head;
    ListNode* tortoise = head;

    while(hare && hare.next)
    {
        if (tortoise == hare)
            return true;
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return false; 
}