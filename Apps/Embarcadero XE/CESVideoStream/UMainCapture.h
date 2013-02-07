

//---------------------------------------------------------------------------

#ifndef UmainCaptureH
#define UmainCaptureH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <queue.h>
#include <Dialogs.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include "CaptureWorkerForm.h"

#ifdef _DEBUG
	#undef _DEBUG  //prevent loading of debug version of library.
	#include "lsl_c.h" //must be "", not <>, otherwise get data corruption in console apps when using dll functions
	#define _DEBUG
#else
	#include "lsl_c.h"
#endif


class TMainCaptureForm : public TForm
{
__published:	// IDE-managed Components

	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TLabel *Label1;
	TComboBox *cbVideoInputDevice;
	TLabel *Label36;
	TComboBox *cbVideoInputFormat;
	TTimer *Timer1;
	TTabSheet *TabSheet1;
	TCheckBox *cbRecord;
	TComboBox *cbVideoCodecs;
	TLabel *Label2;
	TEdit *edOutput;
	TLabel *lbCodecs;
	TLabel *Label4;
	TEdit *edTimestamp;
	TLabel *Label3;
	TEdit *edFrame;
	TBitBtn *BitBtnPlay;
	TBitBtn *BitBtnStop;
	TLabeledEdit *BacklogEdit;
	TLabeledEdit *droppedFramesEdit;
	TOpenDialog *OpenDialog1;
	TXMLDocument *xdoc_in;
	TLabeledEdit *edtFrameRate;
	TLabeledEdit *FrameDivisorEdit;
	TLabeledEdit *SpatialDivisorEdit;
	TCheckBox *cbRecordAudio;
	TCheckBox *cbCompress;
	TComboBox *cbVideoInput;
	TLabel *Label6;
	TPanel *tPanel;
	TPanel *tPanel1;
	TLabeledEdit *BacklogEdit1;
	TLabeledEdit *droppedFramesEdit1;
	TLabeledEdit *droppedFramesEdit2;
	TLabeledEdit *droppedFramesEdit3;
	TLabeledEdit *BacklogEdit2;
	TLabeledEdit *BacklogEdit3;
	TPanel *tPanel2;
	TPanel *tPanel3;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbVideoInputDeviceChange(TObject *Sender);
	void __fastcall cbVideoInputFormatChange(TObject *Sender);
	void __fastcall btStopClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

	/**
	 * Start recording video.
	 */
	void __fastcall cbRecordClick(TObject *Sender);

	/**
	 * Start playing video.
	 */
	void __fastcall BitBtnPlayClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);

	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FrameDivisorEditChange(TObject *Sender);
	void __fastcall SpatialDivisorEditChange(TObject *Sender);
	void __fastcall cbVideoInputChange(TObject *Sender);


private:	// User declarations
	void __fastcall TMainCaptureForm::Start();
	Graphics::TBitmap *pBmpRec;
	Graphics::TBitmap *pBmpPau;
	Graphics::TBitmap *pBmpRecGr;
	Graphics::TBitmap *pBmpPauGr;

	queue<BITMAP*> bmpQueue,bmpQueue1,bmpQueue2,bmpQueue3;
	double crRadiusMultiplier;
	double crRadiusMax;
	double eyeRadiusMax;
	int nOutlinesDesired;
	TCaptureWorkerForm *CaptureWorkerForm;
	TCaptureWorkerForm *CaptureWorkerForm1;
	TCaptureWorkerForm *CaptureWorkerForm2;
	TCaptureWorkerForm *CaptureWorkerForm3;
public:		// User declarations
	/**
	 * Find at fit a circle in the image. Used for tracking the eye, the
	 * calibration spot, or the cornea reflection.
	 */
 //	void findAndFitCircle(BITMAP *aBmp, double *xCenter, double *yCenter, double *radius,
 //		double crX0, double crY0, double crRadius, boolean above,
 //		int tbLeftPosition, int tbRightPosition, int tbLowerPosition, int tbUpperPosition, bool paint);
	/**
	 * Called from the VideoStream.exe project. Sets the application to basic
	 * Video acquisition.
	 */
	void SetToVideoMode();


	Graphics::TBitmap *bmpGaze;

	/**
	 * Process a video frame.
	 *
	 */
	void __fastcall DoFrame(BITMAP *aBmp, HANDLE hMutex);
	__fastcall TMainCaptureForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TMainCaptureForm *MainCaptureForm;
//---------------------------------------------------------------------------
#endif
