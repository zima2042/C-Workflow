#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct WS2812
{
    uint8_t data[3];
    bool connected;
    struct WS2812* next;
} WS2812_t;

WS2812_t* WS2812_Create() {
    WS2812_t* new_node = (WS2812_t*)malloc(sizeof(WS2812_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data[0] = 0;
    new_node->data[1] = 0;
    new_node->data[2] = 0;
    new_node->connected = true;
    new_node->next = NULL;
    return new_node;
}

uint32_t WS2812_Add(WS2812_t* head) {
    if (head == NULL) {
        return UINT32_MAX;
    }

    WS2812_t* new_node = WS2812_Create();
    if (new_node == NULL)
    {
        return UINT32_MAX;
    }

    WS2812_t* current = head;
    uint32_t index = 0;

    while (current->next != NULL)
    {
        current = current->next;
        index++;
    }

    current->next = new_node;

    return index + 1;
}

bool WS2812_SetColor(WS2812_t* head, uint32_t index, uint8_t r, uint8_t g, uint8_t b) {
    if (head == NULL) return false;

    WS2812_t* current = head;
    uint32_t i = 0;

    while (current != NULL)
    {
        if (i == index) {
            if (!current->connected) {
                return false;
            }
            current->data[0] = r;
            current->data[1] = g;
            current->data[2] = b;
            return true;
        }
        current = current->next;
        i++;
    }

    return false;
}

WS2812_t* WS2812_Break(WS2812_t* head, uint32_t index)
{
    if (head == NULL) return NULL;

    WS2812_t* current = head;
    uint32_t i = 0;

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    if (current != NULL)
    {
        while (current != NULL) {
            current->connected = false;
            current = current->next;
        }
    }

    return head;
}

void WS2812_Show(WS2812_t* head)
{
    WS2812_t* current = head;
    uint32_t index = 0;

    while (current != NULL)
    {
        printf("%2u: (%02x,%02x,%02x) %s\n",
            index,
            current->data[0],
            current->data[1],
            current->data[2],
            current->connected ? "true" : "false");
        current = current->next;
        index++;
    }
}

int main(void) {
    WS2812_t* head = WS2812_Create();
    if (!head) return 1;

    for (uint8_t i = 0; i < 14; i++) WS2812_Add(head);
    printf("Add: %d\n", WS2812_Add(head));

    for (uint32_t i = 0; i <= 15; i++)
        WS2812_SetColor(head, i, (uint8_t)(17 * i), 0, (uint8_t)(255 - 17 * i));

    WS2812_SetColor(head, 99, 1, 2, 3);

    printf("\n--- before break ---\n");
    WS2812_Show(head);

    head = WS2812_Break(head, 8);

    printf("\n--- after break(8) ---\n");
    WS2812_Show(head);

    WS2812_SetColor(head, 3, 0xFF, 0xFF, 0xFF);
    WS2812_SetColor(head, 10, 0xFF, 0xFF, 0xFF);

    printf("\n--- SetColor test ---\n");
    WS2812_Show(head);

    printf("Add on NULL: %d\n", WS2812_Add(NULL));
    WS2812_Break(NULL, 0);

    printf("done\n");

    getchar();
    return 0;
}