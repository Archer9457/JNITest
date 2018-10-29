package com.droi.jnitest;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.droi.hellojni.JniUtil;

public class MainActivity extends AppCompatActivity {

    public EditText number_text;
    public Button mButton;
    public Context mContext;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
            // Load the respective library
            System.loadLibrary("OpenDevice_Jni");
        setContentView(R.layout.activity_main);
        mContext = this;
        number_text = findViewById(R.id.edit_text);
        mButton = findViewById(R.id.button1);
        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String text = number_text.getText().toString();
                Toast.makeText(mContext,"输入："+text,Toast.LENGTH_SHORT).show();

                int fd  = JniUtil.openDevice(Long.parseLong(text));
                if( fd > 0 ) {
                    JniUtil.closeDevice(fd);
                }

            }
        });
    }


}
