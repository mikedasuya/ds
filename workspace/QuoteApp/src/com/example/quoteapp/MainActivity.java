package com.example.quoteapp;

import com.example.quoteapp.http.HttpConnection;
import com.example.quoteapp.service.DownloadService;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
     // use this to start and trigger a service
        Intent i= new Intent(this, DownloadService.class);
        // potentially add data to the intent
        //i.putExtra("KEY1", "Value to be used by the service");
        this.startService(i); 
       // HttpConnection con = new HttpConnection();
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }
    
}
