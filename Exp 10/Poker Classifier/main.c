#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

struct Card {
    char suit;
    char rank;
};

char valid_suits[] = {'c', 'd', 'h', 's'};
char valid_ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};

#define VALID_SUITS_CNT 4
#define VALID_RANKS_CNT 13

struct Card cards[5];

int is_valid_card(struct Card card, int nth) {
    int is_rank_valid = 0, is_suits_valid = 0;
    // Validate rank.
    for (int rank_ind = 0; rank_ind < VALID_RANKS_CNT; ++rank_ind) {
        if (valid_ranks[rank_ind] == card.rank) {
            is_rank_valid = 1;
            break;
        }
    }
    // Validate suit.
    for (int suit_ind = 0; suit_ind < VALID_SUITS_CNT; ++suit_ind) {
        if (valid_suits[suit_ind] == card.suit) {
            is_suits_valid = 1;
            break;
        }
    }

    if (!is_rank_valid || !is_suits_valid) {
        return 0;
    }

    // Check duplication
//    if (nth==0){
//        return 1;
//    }
    for (int card_ind = 0; card_ind < nth; ++card_ind) {
        if (cards[card_ind].suit == card.suit && cards[card_ind].rank == card.rank) {
            return 0;
        }
    }
    return 1;
}

struct Card input_card(int nth) {
    char suit, rank;
    printf("Please input the No.%d card:", nth);
    if (nth>0)
        getchar();   // Don't read '\n'.
    scanf("%c%c", &rank, &suit);

    struct Card card;
    card.suit = suit;
    card.rank = rank;

    // Validation
    if (is_valid_card(card, nth)) {
        return card;
    } else {
        printf("[!] Invalid/Duplicate card!\n");
        return input_card(nth);
    }
}

int cmpint(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int get_same_suits_cnt() {
    int cnts[VALID_SUITS_CNT];
    memset(cnts, 0, sizeof(int) * VALID_SUITS_CNT);
    for (int card_ind = 0; card_ind < 5; ++card_ind) {
        char suit = cards[card_ind].suit;
        for (int suit_ind = 0; suit_ind < VALID_SUITS_CNT; ++suit_ind) {
            if (suit == valid_suits[suit_ind]) {
                ++cnts[suit_ind];
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < VALID_SUITS_CNT; ++i) {
        if (cnts[i] > ans)
            ans = cnts[i];
    }
    return ans;
}

int *get_same_ranks_cnt() {
    // Return the sorted same rank count.
    static int cnts[VALID_RANKS_CNT];
    memset(cnts, 0, sizeof(int) * VALID_RANKS_CNT);
    for (int card_ind = 0; card_ind < 5; ++card_ind) {
        char rank = cards[card_ind].rank;
        for (int rank_ind = 0; rank_ind < VALID_RANKS_CNT; ++rank_ind) {
            if (rank == valid_ranks[rank_ind]) {
                ++cnts[rank_ind];
                break;
            }
        }
    }

    qsort(cnts, VALID_RANKS_CNT, sizeof(int), cmpint);

    return cnts;
}


int is_straight() {
    // Look for start.
    int ranks[5];
    for (int rank_ind = 0; rank_ind < 5; ++rank_ind) {
        if (cards[rank_ind].rank == 't')
            ranks[rank_ind] = 10;
        else if (cards[rank_ind].rank == 'j')
            ranks[rank_ind] = 11;
        else if (cards[rank_ind].rank == 'q')
            ranks[rank_ind] = 12;
        else if (cards[rank_ind].rank == 'k')
            ranks[rank_ind] = 13;
        else if (cards[rank_ind].rank == 'a')
            ranks[rank_ind] = 14;
        else
            ranks[rank_ind] = atoi(&cards[rank_ind].rank);
    }
    qsort(ranks, 5, sizeof(int), cmpint);

    for (int rank_ind = 1; rank_ind < 5; ++rank_ind) {
        if (ranks[rank_ind] != ranks[rank_ind - 1] + 1)
            return 0;
    }
    return 1;
}

char *poker_classifier() {
    int *same_ranks_cnt = get_same_ranks_cnt();
    int biggest_same_ranks_cnt = *(same_ranks_cnt+VALID_RANKS_CNT - 1);
    int second_biggest_same_ranks_cnt = *(same_ranks_cnt+VALID_RANKS_CNT - 2);

    int same_suits_cnt = get_same_suits_cnt();
    int straight = is_straight();


    if (same_suits_cnt == 5 && straight)
        return "Straight Flush";
    else if (same_suits_cnt == 4)
        return "Four of A Kind";
    else if (biggest_same_ranks_cnt == 3 && second_biggest_same_ranks_cnt == 2)
        return "Full House";
    else if (same_suits_cnt == 5)
        return "Flush";
    else if (straight)
        return "Straight";
    else if (biggest_same_ranks_cnt == 3)
        return "Three-of-a-kind";
    else if (biggest_same_ranks_cnt == 2 && second_biggest_same_ranks_cnt == 2)
        return "Two Pairs";
    else if (biggest_same_ranks_cnt == 2)
        return "Pair";
    else
        return "High Card";
}

int main() {
    for (int card_ind = 0; card_ind < 5; ++card_ind) {
        cards[card_ind] = input_card(card_ind);
    }

    printf("%s", poker_classifier());

    return 0;
}
