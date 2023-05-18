
bool read_qrd()
{
    bool check_sum;
    byte sum_qrd = 0;
    Serial1.write(0x80);
    //printf("Data odesla %lu  ", millis() );

wait_for_start_sequence:
    while ( ! Serial1.available() )
        sleep(0);

    if(Serial1.read() != 0x80)
        goto wait_for_start_sequence;

    while ( ! Serial1.available() )
        sleep(0);

    if(Serial1.read() != 0x42)
        goto wait_for_start_sequence;

    while(Serial1.available() < 12)
        sleep(0);
  
    //printf("Data prisla, %lu,  ", millis() );


    for(int i = 0; i != 12; ++i) {
            qrd[i] = Serial1.read(); 
            sum_qrd = sum_qrd + qrd[i]; // tvorba checksum
        }
    byte check_byte = Serial1.read();
    if (check_byte == sum_qrd) 
        check_sum = true; else  check_sum = false; 
    //for(byte b = 0; b<12; b++) printf("#%u: %u ",b, qrd[b]); //kontrolni tisk
    printf("Check_sum: %u %u \n", check_byte, sum_qrd );
    
    return check_sum;
}

void end_left(rb::Encoder&)
{  
    end_L = true;
}

void end_right(rb::Encoder&)
{  
    end_R = true;
}

void vpred(float kolik)  // kolik - pocet ctvercu 
{
    rbc().motor(RIGHT_MOTOR)->drive(kolik*ctverec, power_motor, end_right);
    rbc().motor(LEFT_MOTOR)->drive(kolik*ctverec, power_motor, end_left);  
}

void vpravo(float kolik) // kolik - pocet otocek o 90 stupnu
{
    rbc().motor(LEFT_MOTOR)->drive(kolik*zatoc, power_motor, end_left);
    // rbc().motor(RIGHT_MOTOR)->drive(kolik*ctverec, power_motor, end_right);  
}

void vlevo()
{
    
}
