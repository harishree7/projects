

void		MyRadioHWReset(void);
void 		MyRadioSetChannel(uint8 Channel);
uint8		MyRadioGetChannel(void);
void 		MyRadioInit();
void		WritePayloadToRadio(uint8 Payload);
void 		MyRadioStartReceive(void);
unsigned char MyRadioEndReceive(unsigned char RadioState);
unsigned char MyRadioGetReceiveState();