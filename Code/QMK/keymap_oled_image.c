#ifdef OLED_ENABLE

bool oled_task_user() {
    static const char image [] PROGMEM = {

    };
    
    oled_write_raw_p(image, sizeof(image));

    return false;
}

#endif
