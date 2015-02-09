// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include <moai-admob-android/host.h>
#include <moai-admob-android/MOAIAdmobAndroid.h>

//================================================================//
// aku
//================================================================//

//----------------------------------------------------------------//
void MOAIAdmobAndroidAppInitialize () {
}

//----------------------------------------------------------------//
void MOAIAdmobAndroidAppFinalize () {
}

//----------------------------------------------------------------//
void MOAIAdmobAndroidContextInitialize () {
	REGISTER_LUA_CLASS ( MOAIAdmobAndroid )
}