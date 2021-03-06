#ifndef _RECTANGLES_H_
#define _RECTANGLES_H_

#include <d3dx9.h>

#include "game.h"
#include "sprite.h"
#include "MarioObject.h"

#define DIRECT_LEFT 0;
#define DIRECT_RIGHT 1;

//#define MARIO_IMAGE_RIGHT L"mario3.bmp"
//#define MARIO_IMAGE_LEFT L"mario3.bmp"
#define GROUND_MIDDLE L"ground_middle.png"
#define BRICK L"brick.png"
#define CHECK_FALL L"checkFall.png"
#define MARIO_IMAGE L"smallMarioResized.png"

#define MARIO_MAX_SPEED 0.5f
#define MARIO_MIN_SPEED 0.1f
#define MARIO_ACCELERATION_X 0.5f
#define GROUND_Y 45

#define BACKGROUND_FILE L"blocks.png"

#define ANIMATE_RATE 30
#define JUMP_VELOCITY_BOOST 2.5f
#define FALLDOWN_VELOCITY_DECREASE 0.5f

#define GRAV_VELOCITY 0.5f
#define MAX_GRAV 1.0f
//#define VIEW_PORT_Y  600

class CMarioGame : public CGame
{
public:
	CMarioGame(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate);
	~CMarioGame();

	LPD3DXSPRITE _SpriteHandler;

	int mario_x;			// position of mario
	int mario_y;

	float mario_vx;			// velocity of mario
	float mario_vy;

	float mario_vx_last;	// last vx of mario before stop ( to determine the direction of mario )
	
	Mario* mario;

	DWORD last_time;		// this is to control the animate rate of kitty

	//LPDIRECT3DSURFACE9 Background;

	CSprite * marioSprite;

	CSprite * ground_middle;
	CSprite * brick;
	CSprite * mountain;
	CSprite * fallDown;

	bool _IsOnGround;
	bool _IsFallOfGround;
	int direction;
	//Object * fallBox;
	Animation * anim;

protected:
	LPDIRECT3DSURFACE9 _Background;

	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);

	void RenderBackground(int view_port_x, int view_port_y);
};
#endif