package com.sr.hj.libyuv;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.sr.hj.libyuv.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'libyuv' library on application startup.


    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        byte[] yuv = new byte[1280*720*3/2];
        byte[] rgb = new byte[1280*720*4];
        Libyuv.NV21ToRGBA(yuv,rgb,0,0);
    }


}