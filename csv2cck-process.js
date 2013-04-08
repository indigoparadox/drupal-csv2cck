
function csv2cck_radio_exclusive( id_on_in ) {
   // Drupal won't let us set the names of the radio buttons to match and still
   // keep the results, so whatever. This is validated server-side too, so it's
   // OK, right?
   jQuery( '#csv2cck-process-form input:radio' )
      .not( '[id=' + id_on_in + ']' )
      .attr( 'checked', false );
}

