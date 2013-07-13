/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.LudicrousGames.MonkeyDroid;


import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.cocos2dx.lib.Cocos2dxHandler;

import com.LudicrousGames.MonkeyDroid.PeanutCurrency;
import com.soomla.cocos2dx.store.StoreControllerBridge;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Message;

public class CrashTestMonkeys extends Cocos2dxActivity{
	
	private static CrashTestMonkeys me = null;
	
    protected void onCreate(Bundle savedInstanceState){
    	me = this;
		super.onCreate(savedInstanceState);	
		
		/**
         * initialize the StoreControllerBridge
         * You'll need to provide an implementation of IStoreAssets and your public key from Google Play.
         */
        StoreControllerBridge.initialize(mGLSurfaceView,
                new PeanutCurrency(), "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA1vWzdijevVsluTERveWqNByTcTelg1sPYQgqWFAA25h7xZBZjnewZYMZuvc9NOozxrg5vHau+b+IQXyUnwkDz6z+fa1Fu2bzAR/4Mtwkyt73hVFfpNeMcp5AMFzoCDqfVwkwW0CA5JCK3kSDA8q9g2P2SmAx4sI/NmmwmO3dag1ZRIFqskXXnF1ViLgwFjl7Q8u6rFIvuPgQmbZDP8EIX4fPsE+0baXp/unKClz1ueXZ7nKvlFVxk22oeP1lPHkRlCjCUvtUGK/lLCcXHVuAgxMliUXmOHHGx7GjcOhquIEovPxULHObP62DsG+3Q94Dvybpm3VfaxEfwbmnk9lSmwIDAQAB", this);
	}

    
    @Override
	public void onDestroy() {
	    super.onDestroy();
	}
    
    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// CrashTestMonkeys should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }

    static {
        System.loadLibrary("cocos2dcpp");
    }     
    
    public static void openURL(String url)
    {
    	Uri uri = Uri.parse(url);
    	Intent intent = new Intent(Intent.ACTION_VIEW, uri);
    	me.startActivity(intent);
    }
    
    public static void playMovie(String movieName)
    {   	
    	Message msg = new Message();
    	msg.what = Cocos2dxHandler.HANDLER_SHOW_VIDEO;
    	msg.obj = movieName;
    	me.mHandler.sendMessage(msg);
    }
    public static void stopMovie()
    {
    	Message msg = new Message();
    	msg.what = Cocos2dxHandler.HANDLER_STOP_VIDEO;
    	me.mHandler.sendMessage(msg);
    }    
}
