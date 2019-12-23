package com.xiaowei.ndkcpp;

import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {

    private NDKCpp ndkCpp;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        ndkCpp = new NDKCpp();
    }

    public void callCppConstrut(View view) {
        ndkCpp.callCppConstruct();
    }

    public void callCppNewODelete(View view) {
        ndkCpp.callCppNewOrDelete();
    }

    static {
        System.loadLibrary("native-lib");
    }

    public void callCppStatic(View view) {
        ndkCpp.callCppStatic();
    }

    public void callCppObjectSize(View view) {
        ndkCpp.callCppObjectSize();
    }

    public void callCppFriendFuc(View view) {
        ndkCpp.callCppFriendFunc();
    }

    public void callCppFriendClass(View view) {
        ndkCpp.callCppFriendClass();
    }
}
