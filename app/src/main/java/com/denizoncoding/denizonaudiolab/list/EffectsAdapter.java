package com.denizoncoding.denizonaudiolab.list;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.CompoundButton;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;

import com.denizoncoding.denizonaudiolab.R;
import com.denizoncoding.denizonaudiolab.synth.Effect;
import com.denizoncoding.denizonaudiolab.synth.EffectParameter;

import java.util.List;

public class EffectsAdapter extends BaseAdapter {

    private LayoutInflater layoutInflater;
    private List<Effect> effectList;

    public EffectsAdapter(Activity activity, List<Effect> effectList) {

        layoutInflater = (LayoutInflater) activity.getSystemService(
                Context.LAYOUT_INFLATER_SERVICE);
        this.effectList = effectList;
    }

    @Override
    public int getCount() {

        return effectList.size();
    }

    @Override
    public Object getItem(int position) {

        return effectList.get(position);
    }

    @Override
    public long getItemId(int position) {

        return effectList.get(position).getId();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        View containerView = layoutInflater.inflate(R.layout.list_view_item, null);

        LinearLayout effectLayout = containerView.findViewById(R.id.verticalLayout);

        TextView nameText = containerView.findViewById(R.id.effectName);

        Effect effect = effectList.get(position);

        nameText.setText(effect.getName());
        List<EffectParameter> parameterList = effect.getParameterList();

        for (final EffectParameter parameter : parameterList) {

            LinearLayout parameterLayout;

            if (parameter.isSwitchable()) {

                parameterLayout = generateSwitchItem(parameter);

            } else {

                parameterLayout = generateParameterItem(parameter);
            }

            effectLayout.addView(parameterLayout);
        }

        return containerView;
    }

    private LinearLayout generateSwitchItem(final EffectParameter parameter) {

        LinearLayout parameterLayout = (LinearLayout) layoutInflater.inflate(R.layout.switch_layout_item, null);

        ((TextView) parameterLayout.findViewById(R.id.textName)).setText(parameter.getName());

        Switch onOffSwitch = parameterLayout.findViewById(R.id.bypSwitch);
        onOffSwitch.setChecked(parameter.getValue() == 1);

        onOffSwitch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                if (isChecked) {

                    parameter.setValueIn100Range(100);

                } else {

                    parameter.setValueIn100Range(0);
                }
            }
        });

        return parameterLayout;
    }

    private LinearLayout generateParameterItem(final EffectParameter parameter) {

        LinearLayout parameterLayout = (LinearLayout) layoutInflater.inflate(R.layout.parameter_layout_item, null);

        ((TextView) parameterLayout.findViewById(R.id.textName)).setText(parameter.getName());
        final TextView valueText = parameterLayout.findViewById(R.id.textValue);
        valueText.setText(String.format("%.2f", parameter.getValue()));

        SeekBar valueBar = parameterLayout.findViewById(R.id.seekBarValue);

        valueBar.setMax(100);
        int progress = (int) (100 * ((parameter.getValue() - parameter.getMin()) / (parameter.getMax() - parameter.getMin())));
        valueBar.setProgress(progress);

        valueBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

                parameter.setValueIn100Range(progress);
                valueText.setText(String.format("%.2f", parameter.getValue()));
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        return parameterLayout;
    }
}
