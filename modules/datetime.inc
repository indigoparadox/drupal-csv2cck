<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

function csv2cck_field_options_datetime_form( $form, &$form_state ) {
}


/* Return: array( 
 *    'safe_value', A printable version of the field.
 *    'raw_value', The value to store when creating the node with this field.
 */
function csv2cck_field_options_datetime_convert(
   $data, $field_info, $options
) {
   $mktime = strtotime( $data );
   //$mktime = date_convert( $data, DATE_DATETIME, DATE_UNIX, 'EDT' );

   if( $mktime ) {
      return array(
         'safe_value' => format_date( $mktime ),
         'raw_value' => $mktime,
         'valid' => true,
      );
   } else {
      return array(
         'safe_value' => '',
         'raw_value' => '',
         'valid' => false,
      );
   }
}

function csv2cck_field_options_datetime_attachment( $data_array, $field_info ) {
   // Build the branchy array that hangs off of $node->field[language][0].
   if( !empty( $data_array['raw_value'] ) ) {
      return array(
         'value' => format_date(
            $data_array['raw_value'], 'custom', 'Y-m-d H:i:s'
         ),
         'timezone' => date_default_timezone(),
         'timezone_db' => date_default_timezone(),
         'date_type' => 'datetime',
      );
   } else {
      return array();
   }
}

