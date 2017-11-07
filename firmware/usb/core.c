#include <avr/io.h>

static inline uint8_t recv8()
{
    return UEDATX;
}

static inline uint16_t recv16()
{
    uint16_t data;
    data = UEDATX;
    data |= UEDATX << 8;
    return data;
}

static inline void send8(uint8_t data)
{
    UEDATX = data;
}

typedef struct
{
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
}
setup_packet_t;

static void recv_setup_packet(setup_packet_t *setup_packet)
{
    setup_packet->bmRequestType = recv8();
    setup_packet->bRequest = recv8();
    setup_packet->wValue = recv16();
    setup_packet->wIndex = recv16();
    setup_packet->wLength = recv16();
}

static void send_keyboard_report(usb_keyboard_report_t *usb_keyboard_report)
{
    send8(usb_keyboard_report->modifiers);
    send8(0);
    for (uint8_t i=0; i<6; i++)
    {
        send8(usb_keyboard_report->keys[i]);
    }
}
