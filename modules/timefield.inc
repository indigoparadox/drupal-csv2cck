<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

function csv2cck_field_options_timefield_form( $form, &$form_state ) {
}


/* Return: array( 
 *    'safe_value', A printable version of the field.
 *    'raw_value', The value to store when creating the node with this field.
 */
function csv2cck_field_options_timefield_convert(
   $data, $field_info, $options
) {
   $mktime = timefield_time_to_integer( $data );

   if( $mktime ) {
      return array(
         'safe_value' => timefield_integer_to_time(
            array(
               'hour' => 'g',
               'minute' => 'i',
               'separator' => ':',
               'period' => 'a',
               'period_separator' => '',
            ),
            $mktime
            //, 'custom', 'g:i a'
         ),
         'raw_value' => $mktime,
         'valid' => true,
      );
   } else {
      return array( 'safe_value' => '', 'raw_value' => '', 'valid' => false );
   }
}

function csv2cck_field_options_timefield_attachment(
   $data_array, $field_info
) {
   // Build the branchy array that hangs off of $node->field[language][0].
   if( !empty( $data_array['raw_value'] ) ) {
      return array(
         'value' => $data_array['raw_value'],
         'value_formatted' => $data_array['safe_value'],
         'value2_formatted' => '',
      );
   } else {
      return array();
   }
}

