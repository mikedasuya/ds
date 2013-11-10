package com.example.quoteapp.service.interfaces;

import com.example.quoteapp.service.interfaces.CallBack;

interface DownloadInterface {
	
	int registerCallBack(CallBack cb);
	int getQuote();
}

