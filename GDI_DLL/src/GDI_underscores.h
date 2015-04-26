//  GDI_underscores.h
//  The Windows version of the GDI requires underscores on the exported names while
//  the Linux version doesn't.  This file provides a wrapper to provide the required conversions
//  A rather crude hack but I can't find another alternative that allows for the same
//  source files under Windows & Linux

USBDM_GDI_DECLSPEC
DiReturnT _DiGdiClose ( DiBoolT fClose ) {
 return DiGdiClose ( fClose );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiVersion ( DiUInt32T *dnGdiVersion ) {
 return DiGdiVersion ( dnGdiVersion );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiGetFeatures ( pDiFeaturesT pdfFeatures ) {
 return DiGdiGetFeatures ( pdfFeatures );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiSetConfig ( DiStringT szConfig ) {
 return DiGdiSetConfig ( szConfig );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiInitIO ( pDiCommSetupT pdcCommSetup ) {
 return DiGdiInitIO ( pdcCommSetup );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiInitRegisterMap ( DiUInt32T        dnEntries,
                               DiRegisterInfoT   *pdriRegister,
                               DiUInt32T         dnProgramCounter ) {
 return DiGdiInitRegisterMap ( dnEntries, pdriRegister, dnProgramCounter );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiInitMemorySpaceMap ( DiUInt32T            dnEntries,
                                  DiMemorySpaceInfoT   *pdmiMemSpace ) {
 return DiGdiInitMemorySpaceMap ( dnEntries, pdmiMemSpace );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiAddCallback ( DiCallbackT dcCallbackType,
                           CallbackF   Callback ) {
 return DiGdiAddCallback ( dcCallbackType, Callback );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiCancel ( void ) {
 return DiGdiCancel ();
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiSynchronize ( DiBoolT *pfUpdate ) {
 return DiGdiSynchronize ( pfUpdate );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiDirectAddMenuItem ( DiUInt32T    *pdnNrEntries,
                              pDiMenuItemT *pdmiMenuItem ) {
 return DiDirectAddMenuItem ( pdnNrEntries, pdmiMenuItem );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiDirectCommand ( DiStringT    pszCommand,
                          DiUserInfoT *pduiUserInfo ) {
 return DiDirectCommand ( pszCommand, pduiUserInfo );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiDirectReadNoWait ( DiUInt32T  dnNrToRead,
                             char        *pcBuffer,
                             DiUInt32T   *dnNrRead ) {
 return DiDirectReadNoWait ( dnNrToRead, pcBuffer, dnNrRead );
}
USBDM_GDI_DECLSPEC
void _DiErrorGetMessage ( DiConstStringT *pszErrorMsg ) {
 DiErrorGetMessage ( pszErrorMsg );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemorySetMap ( DiMemoryMapT dmmMap ) {
 return DiMemorySetMap ( dmmMap );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemoryGetMap ( DiMemoryMapT *pdmmMap ) {
 return DiMemoryGetMap ( pdmmMap );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemorySetCpuMap ( DiMemoryToCpuT dmtcMap ) {
 return DiMemorySetCpuMap ( dmtcMap );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemoryGetCpuMap ( DiMemoryToCpuT *pdmtcMap ) {
 return DiMemoryGetCpuMap ( pdmtcMap );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemoryDownload ( DiBoolT            fUseAuxiliaryPath,
                           DiDownloadCommandT ddcDownloadCommand,
                           DiDownloadFormatT  ddfDownloadFormat,
                           char               *pchBuffer ) {
 return DiMemoryDownload ( fUseAuxiliaryPath, ddcDownloadCommand, ddfDownloadFormat, pchBuffer );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemoryWrite ( DiAddrT      daTarget,
                        DiMemValueT  *pdmvBuffer,
                        DiUInt32T    dnBufferItems ) {
 return DiMemoryWrite ( daTarget, pdmvBuffer, dnBufferItems );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMemoryRead ( DiAddrT       daTarget,
                       DiMemValueT   *pdmvBuffer,
                       DiUInt32T     dnBufferItems ) {
 return DiMemoryRead ( daTarget, pdmvBuffer, dnBufferItems );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiRegisterWrite ( DiUInt32T        dnRegNumber,
                          DiRegisterValueT drvValue ) {
 return DiRegisterWrite ( dnRegNumber, drvValue );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiRegisterRead ( DiUInt32T         dnRegNumber,
                         pDiRegisterValueT drvValue ) {
 return DiRegisterRead ( dnRegNumber, drvValue );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiRegisterClassCreate ( DiUInt32T *pdnRegClassId,
                                DiUInt32T *pdnRegisterId,
                                DiUInt32T dnRegisterIdEntries ) {
 return DiRegisterClassCreate ( pdnRegClassId, pdnRegisterId, dnRegisterIdEntries );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiRegisterClassDelete ( DiUInt32T dnRegClassId ) {
 return DiRegisterClassDelete ( dnRegClassId );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiRegisterClassWrite ( DiUInt32T         dnRegClassId,
                               DiRegisterValueT  *pdrvClassValue ) {
 return DiRegisterClassWrite ( dnRegClassId, pdrvClassValue );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiRegisterClassRead ( DiUInt32T          dnRegClassId,
                              DiRegisterValueT   *pdrvClassValue ) {
 return DiRegisterClassRead ( dnRegClassId, pdrvClassValue );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiBreakpointSet ( DiBpResultT *pdnBreakpointId,
                          DiBpT        dbBreakpoint ) {
 return DiBreakpointSet ( pdnBreakpointId, dbBreakpoint );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiBreakpointClear ( DiUInt32T dnBreakpointId ) {
 return DiBreakpointClear ( dnBreakpointId );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiBreakpointClearAll ( void ) {
 return DiBreakpointClearAll ();
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecResetChild ( void ) {
 return DiExecResetChild () ;
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecSingleStep ( DiUInt32T dnNrInstructions ) {
 return DiExecSingleStep ( dnNrInstructions );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecContinueUntil ( DiAddrT addrUntil ) {
 return DiExecContinueUntil ( addrUntil );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecContinue ( void ) {
 return DiExecContinue ();
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecContinueBackground ( void ) {
 return DiExecContinueBackground ();
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecGetStatus ( pDiExitStatusT pdesExitStatus ) {
 return DiExecGetStatus ( pdesExitStatus );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiExecStop ( void ) {
 return DiExecStop ();
}
USBDM_GDI_DECLSPEC
DiReturnT _DiTraceSwitchOn ( DiBoolT fOn ) {
 return DiTraceSwitchOn ( fOn );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiTraceGetInstructions ( DiUInt32T       dnNrInstr,
                                 pDiInstrTraceT  pditInstrTrace ) {
 return DiTraceGetInstructions ( dnNrInstr, pditInstrTrace );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiTracePrintRawInfo ( DiUInt32T       dnNrFrames,
                              DiTraceTypeT    dttTraceType,
                              PrintRawTraceF  PrintRawTrace ) {
 return DiTracePrintRawInfo ( dnNrFrames, dttTraceType, PrintRawTrace );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiTraceGetNrOfNewFrames ( DiTraceTypeT   dttTraceType,
                                  DiUInt32T      dnNrMaxFrames,
                                  pDiNewFramesT  pdnfNewFrames ) {
 return DiTraceGetNrOfNewFrames ( dttTraceType, dnNrMaxFrames, pdnfNewFrames );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiCoverageSwitchOn ( DiBoolT fOn ) {
 return DiCoverageSwitchOn ( fOn )  ;
}
USBDM_GDI_DECLSPEC
DiReturnT _DiCoverageGetInfo ( DiAddrT     daStart,
                            DiUInt32T   dnSize,
                            DiCoverageT *pdcCoverage ) {
 return DiCoverageGetInfo ( daStart, dnSize, pdcCoverage );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiProfilingSwitchOn ( DiBoolT fOn ) {
 return DiProfilingSwitchOn ( fOn );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiProfileGetInfo ( DiProfileT *pdpProfile ) {
 return DiProfileGetInfo ( pdpProfile );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiStateOpen ( DiUInt32T *pdnStateHandle,
                      DiStringT szStateName ) {
 return DiStateOpen ( pdnStateHandle, szStateName );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiStateSave ( DiUInt32T dnStateHandle,
                       DiUInt32T dnIndex ) {
 return DiStateSave ( dnStateHandle, dnIndex );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiStateRestore ( DiUInt32T dnStateHandle,
                         DiUInt32T dnIndex ) {
 return DiStateRestore ( dnStateHandle, dnIndex );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiStateClose ( DiBoolT fDelete ) {
 return DiStateClose ( fDelete );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiCommGetAcceptableSettings ( DiCommChannelT   dccType,
                                         DiConstStringT   szAttr,
                                         DiConstStringT   *pszEntries[],
                                         void             *pReserved ) {
 return DiCommGetAcceptableSettings ( dccType, szAttr, pszEntries, pReserved );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMeeEnumExecEnv ( DiExecEnvT *pdExecEnv ) {
 return DiMeeEnumExecEnv ( pdExecEnv );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMeeConnect ( DiUInt32T dnExecId ) {
 return DiMeeConnect ( dnExecId );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMeeGetFeatures ( DiUInt32T    dnExecId,
                           pDiFeaturesT pdfFeatures ) {
 return DiMeeGetFeatures ( dnExecId, pdfFeatures ) ;
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMeeInitIO ( DiUInt32T      dnExecId,
                      pDiCommSetupT  pdcCommSetup ) {
 return DiMeeInitIO ( dnExecId, pdcCommSetup ) ;
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMeeSelect ( DiUInt32T dnExecId ) {
 return DiMeeSelect ( dnExecId );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiMeeDisconnect ( DiUInt32T  dnExecId,
                          DiBoolT    fClose ) {
 return DiMeeDisconnect ( dnExecId, fClose );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiCpuSelect ( DiUInt32T dnCpuId ) {
 return DiCpuSelect ( dnCpuId );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiCpuCurrent ( DiUInt32T *dnCpuId ) {
 return DiCpuCurrent ( dnCpuId );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiProcess ( void *information ) {
 return DiProcess ( information );
}
USBDM_GDI_DECLSPEC
DiReturnT _DiGdiOpen ( DiUInt32T      dnGdiVersionH,
                       DiUInt32T      dnGdiVersionL,
                       DiUInt32T      dnArgc,
                       DiConstStringT szArgv[],
                       void (*UdProcessEvents)(void) ) {
 return DiGdiOpen ( dnGdiVersionH,
                    dnGdiVersionL,
                    dnArgc,
                    szArgv,
                    UdProcessEvents);
}
